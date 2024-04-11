mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    N = int(input())
    A = list(map(int, input().split()))

    ans = 0
    prev = -1
    B = []
    for i, a in enumerate(A):
        if a != prev:
            ans += 1
        else:
            B.append((a, i))
        prev = a

    if B:
        ans += 1
    for i in range(len(B) - 1):
        if B[i][0] != B[i+1][0]:
            ans += 1
        else:
            ok = 0
            b = B[i][0]
            for j in range(B[i][1]+1, B[i+1][1]):
                if A[j] != b:
                    if A[j-1] != b or A[j+1] != b:
                        ok = 1
                        break
            if ok:
                ans += 1
    print(ans)


if __name__ == '__main__':
    main()