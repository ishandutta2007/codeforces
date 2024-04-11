def main():
    import sys
    from collections import Counter
    input = sys.stdin.readline

    q = int(input())
    for _ in range(q):
        N = int(input())
        A = list(map(int, input().split()))

        C = Counter(A)
        for i in range(11):
            C[2**(i+1)] += C[2**i] // 2
        if C[2048]:
            print('YES')
        else:
            print('NO')


if __name__ == '__main__':
    main()