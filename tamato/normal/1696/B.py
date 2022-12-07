mod = 998244353


def main():
    import sys
    input = sys.stdin.buffer.readline

    for _ in range(int(input())):
        N = int(input())
        A = list(map(int, input().split()))

        if sum(A) == 0:
            print(0)
        else:
            while A:
                if A[-1] == 0:
                    A.pop()
                else:
                    break
            A.reverse()
            while A:
                if A[-1] == 0:
                    A.pop()
                else:
                    break
            if 0 in A:
                print(2)
            else:
                print(1)


if __name__ == '__main__':
    main()