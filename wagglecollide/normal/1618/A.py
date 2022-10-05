for _ in range(int(input())):
    a = sorted(list(map(int, input().split())))
    for i in range(len(a)):
        for j in range(i + 1, len(a)):
            for k in range(j + 1, len(a)):
                if a[i] + a[j] + a[k] == a[-1]:
                    print(a[i], a[j], a[k])
                    break
            else:
                continue
            break
        else:
            continue
        break