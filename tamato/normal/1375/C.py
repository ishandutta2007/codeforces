mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline
    
    for _ in range(int(input())):
        N = int(input())
        P = list(map(int, input().split()))

        if P[0] < P[-1]:
            print("YES")
        else:
            print("NO")


if __name__ == '__main__':
    main()