import sys
import math


def main():
    n, m, k = map(int, input().split())
    if k <= n - 1:
        print(k+1, 1)
        return
    m -= 1
    k -= n
    skip = k // m
    x = n - skip
    if skip % 2 == 0:
        y = 2 + k % m
    else:
        y = m + 1 - k % m
    print(x, y)


if __name__ == '__main__':
    main()