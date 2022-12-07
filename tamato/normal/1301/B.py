def main():
    import sys
    input = sys.stdin.readline

    t = int(input())
    for _ in range(t):
        N = int(input())
        A = list(map(int, input().split()))


        B = []
        D = []
        for i, a in enumerate(A):
            if a == -1:
                if i != 0:
                    if A[i-1] >= 0:
                        B.append(A[i-1])
                if i != N-1:
                    if A[i+1] >= 0:
                        B.append(A[i+1])
            else:
                if i != 0:
                    if A[i-1] >= 0:
                        D.append(abs(A[i] - A[i-1]))
        if not B:
            print(0, 0)
            continue
        if D:
            d = max(D)
        else:
            d = 0
        B.sort()
        k = (B[-1] + B[0]) // 2
        print(max(B[-1] - k, d), k)


if __name__ == '__main__':
    main()