import sys
import math


def main():
    input()
    s = input()
    if s == '0':
        print(s)
    else:
        res = '1'
        for c in s[1:]:
            if c == '0':
                res += c
        print(res)


if __name__ == '__main__':
    main()