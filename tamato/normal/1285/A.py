def main():
    import sys
    input = sys.stdin.readline

    N = int(input())
    s = input()

    n = s.count('R')
    print(n + (N-n) + 1)


if __name__ == '__main__':
    main()