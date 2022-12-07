def main():
    import sys
    input = sys.stdin.readline

    K = int(input())
    print(3, 3)
    X = (1 << (K.bit_length()+1))-1
    Y = 1 << K.bit_length()
    print(X, K, 0)
    print(Y, X, X)
    print(0, X, K)


if __name__ == '__main__':
    main()