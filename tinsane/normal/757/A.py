import collections


def main():
    s = input()
    cou = collections.Counter(s)
    bul = 'Bulbasaur'
    cou2 = collections.Counter(bul)
    res = 10**9
    for item in cou2:
        res = min(res, cou[item] // cou2[item])
    print(res)


if __name__ == '__main__':
    main()