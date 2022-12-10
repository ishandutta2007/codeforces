import collections as col
import itertools as its
import copy


def main():
    s = set()
    a, b = input().split(' ')
    s.add(a)
    s.add(b)
    n = int(input())
    for i in range(n):
        print(' '.join(list(s)))
        a, b = input().split()
        s.remove(a)
        s.add(b)
    print(' '.join(list(s)))


if __name__ == '__main__':
    main()