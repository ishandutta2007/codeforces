mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N = int(input())
        A = list(map(int, input().split()))
        cnt = 0
        for a in A:
            if a & 1:
                cnt += 1
        if cnt == N:
            print("Yes")
        else:
            print("No")


if __name__ == '__main__':
    main()