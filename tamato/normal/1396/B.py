mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N = int(input())
        A = list(map(int, input().split()))

        A.sort()
        if sum(A) & 1:
            print("T")
        else:
            if A[-1] * 2 > sum(A):
                print("T")
            else:
                print("HL")


if __name__ == '__main__':
    main()