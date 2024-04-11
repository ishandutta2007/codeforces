mod = 998244353


def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N = int(input())
        S = input().rstrip('\n')

        ans = 0
        seen = [0] * (N+1)
        for d in range(1, N + 1):
            for x in range(1, N+1):
                if d * x > N:
                    break
                if S[d * x - 1] == "1":
                    break
                if seen[d * x] == 0:
                    ans += d
                    seen[d * x] = 1
        print(ans)


if __name__ == '__main__':
    main()