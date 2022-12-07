mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline

    N = int(input())
    A = list(map(int, input().split()))
    ii = -1
    for i in range(N):
        if A[i] == N:
            ii = i
            break
    ok = 1
    for i in range(ii):
        if A[i+1] < A[i]:
            ok = 0
            break
    for i in range(ii+1, N):
        if A[i] > A[i-1]:
            ok = 0
            break
    if ok:
        print("YES")
    else:
        print("NO")


if __name__ == '__main__':
    main()