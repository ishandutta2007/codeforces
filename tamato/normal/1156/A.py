mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    N = int(input())
    A = list(map(int, input().split()))
    ans = 0
    for i in range(1, N):
        if A[i-1] == 1:
            if A[i] == 2:
                ans += 3
            else:
                ans += 4
        elif A[i-1] == 2:
            if A[i] == 1:
                ans += 3
            else:
                print("Infinite")
                exit()
        elif A[i-1] == 3:
            if A[i] == 1:
                ans += 4
            else:
                print("Infinite")
                exit()

    for i in range(N-2):
        if A[i] == 3 and A[i+1] == 1 and A[i+2] == 2:
            ans -= 1

    print("Finite")
    print(ans)


if __name__ == '__main__':
    main()