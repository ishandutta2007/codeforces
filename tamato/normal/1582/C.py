mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N = int(input())
        S = input().rstrip('\n')

        ans_best = N+1
        for i in range(26):
            c = chr(97 + i)
            T = []
            for s in S:
                if s != c:
                    T.append(s)
            ok = 1
            for j in range(len(T) // 2):
                if T[j] != T[-j-1]:
                    ok = 0
                    break
            if not ok:
                continue
            A = [0]
            for s in S:
                if s == c:
                    A[-1] += 1
                else:
                    A.append(0)
            ans = 0
            for j in range(len(A) // 2):
                ans += abs(A[j] - A[-j-1])
            ans_best = min(ans, ans_best)
        if ans_best < N+1:
            print(ans_best)
        else:
            print(-1)


if __name__ == '__main__':
    main()