def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        x = input().rstrip('\n')
        y = input().rstrip('\n')
        X = int(x, 2)
        Y = int(y, 2)
        ky = (Y & -Y).bit_length()
        for i in range(ky, len(x)+1):
            if x[-i] == '1':
                k = i-ky
                break
        print(k)


if __name__ == '__main__':
    main()