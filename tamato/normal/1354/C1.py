mod = 1000000007
eps = 10**-9


def main():
    import sys
    from math import sin, pi, cos
    input = sys.stdin.readline

    for _ in range(int(input())):
        N = int(input())
        NN = N*2

        print(cos(pi / NN) / sin(pi / NN))


if __name__ == '__main__':
    main()