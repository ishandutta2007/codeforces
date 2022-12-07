def main():
    import sys
    from bisect import bisect_left
    input = sys.stdin.readline

    N, K, D = map(int, input().split())
    A = list(map(int, input().split()))
    A.sort()

    part = [0] * (N+2)
    part[0] = 1
    part[1] = -1
    for i, a in enumerate(A):
        part[i] += part[i-1]
        if part[i]:
            j = bisect_left(A, a+D+1)
            if j >= i+K:
                part[i+K] += 1
                part[j+1] -= 1
    part[N] += part[N-1]
    if part[N]:
        print('YES')
    else:
        print('NO')
    #print(A)
    #print(part)


if __name__ == '__main__':
    main()