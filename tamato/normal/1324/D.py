def main():
    import sys
    from bisect import bisect_left
    input = sys.stdin.readline

    N = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    C = [a-b for a, b in zip(A, B)]
    C.sort()

    ans = 0
    for i, c in enumerate(C):
        j = bisect_left(C, -c+1)
        ans += N-j
        if c > 0:
            ans -= 1
    print(ans // 2)


if __name__ == '__main__':
    main()