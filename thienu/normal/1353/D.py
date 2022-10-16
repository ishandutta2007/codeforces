

def solve():
    n = int(input())
    small = n-1
    large = n
    indexes = [(0, True)] # i, is_large
    ans = [0 for i in range(n)]
    x = 1
    while large > 2:
        # print(small, large, ans, indexes)
        new_indexes = []
        large_indexes = []
        small_indexes = []
        for i, is_large in indexes:
            if is_large:
                large_indexes.append(i + (large - 1) // 2)
                if large % 2 == 0:
                    new_indexes.append((i, False))
                    new_indexes.append((i + (large-1) // 2 + 1, True))
                else:
                    new_indexes.append((i, True))
                    new_indexes.append((i + (large-1) // 2 + 1, True))
            elif small > 0:
                small_indexes.append(i + (small - 1) // 2)
                if small % 2 == 0:
                    new_indexes.append((i, False))
                    new_indexes.append((i + (small-1) // 2 + 1, True))
                else:
                    new_indexes.append((i, False))
                    new_indexes.append((i + (small-1) // 2 + 1, False))
        for i in large_indexes:
            ans[i] = x
            x += 1
        for i in small_indexes:
            ans[i] = x
            x += 1
        indexes = new_indexes
        small = (small + large - 2) // 4
        large = small + 1
    # print(small, large, ans, indexes)
    if large == 2:
        for i, is_large in indexes:
            if is_large:
                ans[i] = x
                x += 1
        for i, is_large in indexes:
            if is_large:
                ans[i+1] = x
            else:
                ans[i] = x
            x += 1
    elif large == 1:
        for i, is_large in indexes:
            if is_large:
                ans[i] = x
                x += 1
    print(" ".join(map(str, ans)))

if __name__ == '__main__':
    t = int(input())
    for tc in range(t):
        solve()