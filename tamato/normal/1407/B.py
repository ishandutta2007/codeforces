mod = 1000000007
eps = 10**-9


def main():
    import sys
    from math import gcd
    input = sys.stdin.buffer.readline

    for _ in range(int(input())):
        N = int(input())
        A = list(map(int, input().split()))
        A.sort()
        cur = A[-1]
        ans = [cur]
        A.pop()
        for _ in range(N-1):
            G = []
            for a in A:
                G.append((gcd(cur, a), a))
            G.sort(key=lambda x: x[0])
            cur, a = G.pop()
            ans.append(a)
            A = [Gj[1] for Gj in G]
        print(*ans)


if __name__ == '__main__':
    main()