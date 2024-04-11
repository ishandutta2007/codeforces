def main():
    import sys
    from collections import defaultdict
    input = sys.stdin.readline

    t = int(input())
    for _ in range(t):
        N = int(input())
        A = list(map(int, input().split()))
        idx = defaultdict(int)
        ans = 10**9
        for i, a in enumerate(A):
            if idx[a] == 0:
                idx[a] = i+1
            else:
                ans = min(ans, i+1 - idx[a] + 1)
                idx[a] = i+1
        if ans == 10**9:
            print(-1)
        else:
            print(ans)


if __name__ == '__main__':
    main()