mod = 998244353


def main():
    import sys
    input = sys.stdin.buffer.readline

    for _ in range(int(input())):
        N, z = map(int, input().split())
        A = list(map(int, input().split()))
        ans = max(A)
        for a in A:
            ans = max(ans, a | z)
        print(ans)


if __name__ == '__main__':
    main()