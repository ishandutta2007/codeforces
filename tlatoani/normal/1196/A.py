for _ in range(int(input())):
    piles = sorted(list(map(int, input().split())))
    print(piles[1] + ((piles[2] - (piles[1] - piles[0])) >> 1))