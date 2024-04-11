mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N, K = map(int, input().split())
        S = input().rstrip('\n')

        N0 = 0
        N1 = 0
        ok = 1
        for k in range(K):
            flg = -1
            for j in range(N):
                i = j*K+k
                if i >= N:
                    break
                if S[i] == "0":
                    if flg == 1:
                        ok = 0
                    else:
                        flg = 0
                elif S[i] == "1":
                    if flg == 0:
                        ok = 0
                    else:
                        flg = 1
            if flg == 0:
                N0 += 1
            elif flg == 1:
                N1 += 1
        if N0*2 <= K and N1*2 <= K and ok == 1:
            print("YES")
        else:
            print("NO")


if __name__ == '__main__':
    main()