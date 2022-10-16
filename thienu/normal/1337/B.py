def calculate_case():
    hp, void, lightning = map(int, input().split())
    for i in range(void):
        if hp <= 20:
            break
        hp = hp // 2 + 10
    for i in range(lightning):
        hp = hp - 10
    if hp <= 0:
        print("YES")
    else:
        print("NO")

if __name__ == "__main__":
    test_cases = int(input())
    for i in range(test_cases):
        calculate_case()