def main():
    import sys
    input = sys.stdin.readline

    N = int(input())
    line1 = ['B' if i%2 else 'W' for i in range(N)]
    line2 = ['W' if i%2 else 'B' for i in range(N)]
    line1 = ''.join(line1)
    line2 = ''.join(line2)
    for i in range(N):
        if i%2:
            print(line1)
        else:
            print(line2)


if __name__ == '__main__':
    main()