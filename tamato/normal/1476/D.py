mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N = int(input())
        S = input().rstrip('\n')

        cs_L = [0] * (N+1)
        for i, s in enumerate(S):
            if i != 0:
                if S[i-1] != s:
                    cs_L[i+1] = cs_L[i] + 1
                else:
                    cs_L[i+1] = 1
            else:
                cs_L[i+1] = 1
        cs_R = [0] * (N+1)
        for i in range(N-1, -1, -1):
            s = S[i]
            if i != N-1:
                if S[i+1] != s:
                    cs_R[i] = cs_R[i+1] + 1
                else:
                    cs_R[i] = 1
            else:
                cs_R[i] = 1

        ans = []
        for i in range(N+1):
            x = 1
            if i != 0:
                if S[i-1] == "L":
                    x += cs_L[i]
            if i != N:
                if S[i] == "R":
                    x += cs_R[i]
            ans.append(x)
        print(*ans)


if __name__ == '__main__':
    main()