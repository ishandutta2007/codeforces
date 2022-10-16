import itertools

INF = 1 << 300 - 1

def calc(a, b, c):
    return 2*(a*a+b*b+c*c-a*b-b*c-c*a)

def binsearch_lt(a, target):
    left = 0
    right = len(a) - 1
    while left + 1 < right:
        mid = (left + right) // 2
        if target <= a[mid]:
            right = mid
        if target >= a[mid]:
            left = mid
    if a[right] <= target:
        return a[right]
    return a[left]

def binsearch_gt(a, target):
    left = 0
    right = len(a) - 1
    while left + 1 < right:
        mid = (left + right + 1) // 2
        if target <= a[mid]:
            right = mid
        if target >= a[mid]:
            left = mid
    if a[left] >= target:
        return a[left]
    return a[right]

def calculate_case():
    n = list(map(int, input().split()))
    weights = [sorted(list(map(int, input().split()))) for i in range(3)]
    best = INF
    for x, y, z in itertools.permutations((0, 1, 2)):
        for a in weights[x]:
            b = binsearch_gt(weights[y], a)
            c1, c2 = binsearch_lt(weights[z], (a+b)//2), binsearch_gt(weights[z], (a+b)//2)
            best = min(best, calc(a, b, c1), calc(a, b, c2))
    print(best)

if __name__ == "__main__":
    test_cases = int(input())
    for i in range(test_cases):
        calculate_case()