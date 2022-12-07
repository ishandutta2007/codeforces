def main():
    import sys
    input = sys.stdin.readline

    t = int(input())
    for _ in range(t):
        A = input().rstrip('\n')
        B = input().rstrip('\n')
        C = input().rstrip('\n')
        N = len(A)

        ok = 1
        for i in range(N):
            if A[i] != C[i] and B[i] != C[i]:
                ok = 0
                break
        if ok:
            print('YES')
        else:
            print('NO')


if __name__ == '__main__':
    main()