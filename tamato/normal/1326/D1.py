def main():
    import sys
    input = sys.stdin.readline

    # 
    # R[2*i] = L: S[i]
    # R[2*i+1] = L: S[i:i+2]
    #  R[i] 
    def manacher(S):
        C = []
        for a in S:
            C.append(a)
            C.append(0)
        C.pop()

        L = len(C)

        R = [0] * L

        i = j = 0
        while i < L:
            while j <= i < L - j and C[i - j] == C[i + j]:
                j += 1
            R[i] = j
            k = 1
            while j - R[i - k] > k <= i < L - k:
                R[i + k] = R[i - k]
                k += 1
            i += k
            j -= k
        return R

    for _ in range(int(input())):
        S = input().rstrip('\n')
        N = len(S)
        if N == 1:
            print(S)
            continue
        ii = -1
        for i in range(N//2):
            if S[i] != S[N-1-i]:
                break
            ii = i
        if ii >= 0:
            ss = S[:ii+1]
            S = S[ii+1:N-ii-1]
        else:
            ss = ''
        N = len(S)
        if N == 0:
            print(''.join([ss, ss[::-1]]))
            continue
        R = manacher(S)
        M = 0
        iii = 0
        for i in range(N):
            if R[i*2] > M:
                if R[i*2]%2 == 0:
                    continue
                k = R[i*2] // 2
                if i-k == 0 or i+k == N-1:
                    M = R[i*2]
                    iii = i
        for i in range(N-1):
            if R[i*2+1] > M:
                if R[i*2+1]%2 == 1:
                    continue
                k = R[i*2+1] // 2
                if i-k+1 == 0 or i+k == N-1:
                    M = R[i*2+1]
                    iii = i
        if M & 1:
            ans = S[iii - M//2: iii + M // 2 + 1]
        else:
            ans = S[iii - M // 2 + 1: iii + M // 2 + 1]
        print(''.join([ss, ans, ss[::-1]]))
        #print(S, R, iii, M)


if __name__ == '__main__':
    main()