mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N, D = map(int, input().split())
        A = list(map(int, input().split()))
        A.sort()
        if A[0] + A[1] <= D or A[-1] <= D:
            print("YES")
        else:
            print("NO")


if __name__ == '__main__':
    main()