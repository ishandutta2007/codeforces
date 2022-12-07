mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    a, b, k = map(int, input().split())

    if a == 0:
        if k == 0:
            print("Yes")
            print("1" * b)
            print("1" * b)
        else:
            print("No")
        exit()

    if b == 1:
        if k == 0:
            print("Yes")
            print("".join(["1", "0" * a]))
            print("".join(["1", "0" * a]))
        else:
            print("No")
        exit()

    if k > a+b-2:
        print("No")
        exit()

    if k == 0:
        print("Yes")
        print("".join(["1" * b, "0" * a]))
        print("".join(["1" * b, "0" * a]))
        exit()

    R = ["0"] * (a-1) + ["1"] * (b-2)
    X = ["1"]
    Y = ["1"]
    for _ in range(a+b-k-2):
        s = R.pop()
        X.append(s)
        Y.append(s)
    X.append("1")
    Y.append("0")
    for _ in range(k-1):
        s = R.pop()
        X.append(s)
        Y.append(s)
    X.append("0")
    Y.append("1")
    X = "".join(X)
    Y = "".join(Y)

    print("Yes")
    print(X)
    print(Y)


if __name__ == '__main__':
    main()