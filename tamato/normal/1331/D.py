def main():
    import sys
    input = sys.stdin.readline

    S = input().rstrip('\n')
    print(int(S[-1]) & 1)


if __name__ == '__main__':
    main()