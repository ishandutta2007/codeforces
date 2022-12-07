mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline

    for _ in range(int(input())):
        N = int(input())
        A = list(map(int, input().split()))

        B = [0] * N
        ans = 0
        for i, a in enumerate(A):
            b = B[i]
            if b < a-1:
                ans += a-1 - b
            for j in range(2, a+1):
                if i+j >= N:
                    break
                B[i+j] += 1
            if b >= a:
                if i+1 < N:
                    B[i+1] += b - (a-1)
        print(ans)


if __name__ == '__main__':
    main()