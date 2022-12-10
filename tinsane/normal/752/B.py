import operator
import itertools


def main():
    a, b = input(), input()
    ps = set(zip(a, b))
    ps = set(map(lambda p: (min(p), max(p)), ps))
    good = set(map(operator.itemgetter(0), filter(lambda p: p[0] == p[1], ps)))
    ps = set(filter(lambda p: p[0] != p[1], ps))
    bad = set(itertools.chain(*ps))
    if len(bad) != 2 * len(ps) or len(bad.intersection(good)):
        print('-1')
        return
    print(len(ps))
    for p in ps:
        print(p[0], p[1])


if __name__ == '__main__':
    main()