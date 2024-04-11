INF = 10 ** 9 + 5

def calculate_case():
    n = int(input())
    a = list(map(int, input().split(" ")))
    max_inc = 0
    max_so_far = -INF
    for i in a:
        diff = max_so_far - i
        max_inc = max(max_inc, diff)
        max_so_far = max(max_so_far, i)
    time = 0
    while 2 ** time <= max_inc:
        time += 1
    return time



if __name__ == "__main__":
    test_cases = int(input())
    for i in range(1, test_cases + 1):
        print(calculate_case())