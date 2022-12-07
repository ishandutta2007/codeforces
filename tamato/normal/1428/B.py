mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N = int(input())
        S = input().rstrip('\n')

        if ">" not in S or "<" not in S:
            print(N)
            continue

        ans = 0
        for i in range(N):
            if S[i] == "-" or S[(i+1)%N] == "-":
                ans += 1
        print(ans)


if __name__ == '__main__':
    main()