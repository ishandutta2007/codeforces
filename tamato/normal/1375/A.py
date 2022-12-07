mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline
    
    for _ in range(int(input())):
        N = int(input())
        A = list(map(int, input().split()))
        B = []
        for i, a in enumerate(A):
            if i%2 == 0:
                if a > 0:
                    B.append(a)
                else:
                    B.append(-a)
            else:
                if a > 0:
                    B.append(-a)
                else:
                    B.append(a)
        print(*B)


if __name__ == '__main__':
    main()