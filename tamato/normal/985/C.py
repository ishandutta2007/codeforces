def main():
    import sys
    input = sys.stdin.readline

    N, K, L = map(int, input().split())
    A = list(map(int, input().split()))
    A.sort()

    amin = A[0]
    amax = amin + L
    B = []
    C = []
    for i, a in enumerate(A):
        if a > amax:
            break
        if i%K == 0:
            B.append(a)
        else:
            C.append(a)
    for _ in range(N - len(B)):
        if not C:
            print(0)
            exit()
        B.append(C.pop())
    print(sum(B))


if __name__ == '__main__':
    main()