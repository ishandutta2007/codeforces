def main():
    import sys
    input = sys.stdin.buffer.readline

    for _ in range(int(input())):
        x = int(input())
        print(1, x-1)


if __name__ == '__main__':
    main()