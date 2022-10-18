def calculate_case():
    a, b, c, d = map(int, input().split())
    print("{} {} {}".format(b, c, c))


if __name__ == "__main__":
    test_cases = int(input())
    for i in range(test_cases):
        calculate_case()