for _ in range(int(input())):
    k = int(input().split()[1])
    prices = list(map(int, input().split()))
    if max(prices) - k > min(prices) + k:
        print(-1)
    else:
        print(min(prices) + k)