def main():
    import sys
    input = sys.stdin.buffer.readline

    for _ in range(int(input())):
        N = int(input())
        A = list(map(int, input().split()))

        A = set(A)
        print(len(A))


if __name__ == '__main__':
    main()