mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline

    for _ in range(int(input())):
        N, u, v = map(int, input().split())
        A = list(map(int, input().split()))
        if len(set(A)) == 1:
            print(min(u+v, v*2))
        else:
            flg = 1
            for i in range(N-1):
                if abs(A[i+1] - A[i]) > 1:
                    flg = 0
                    break
            if flg:
                print(min(u, v))
            else:
                print(0)


if __name__ == '__main__':
    main()