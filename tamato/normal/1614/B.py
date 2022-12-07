mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N = int(input())
        A = list(map(int, input().split()))

        ans = [0] * (N+1)
        T = 0
        AI = [(a, i) for i, a in enumerate(A)]
        AI.sort(key=lambda x: x[0], reverse=True)
        for j, ai in enumerate(AI):
            a, i = ai
            T += a * ((j + 2) // 2) * 2
            if j & 1:
                ans[i+1] = -((j+2) // 2)
            else:
                ans[i + 1] = (j + 2) // 2
        print(T)
        print(*ans)


if __name__ == '__main__':
    main()