
def main():
    x, y, m = [int(t) for t in raw_input().split()]

    if max(x, y) >= m:
        print 0
    else:
        if x <= 0 and y <= 0:
            print -1
        else:
            cnt = 0
            if x < 0:
                cnt += -x / y
                x += cnt * y
            elif y < 0:
                cnt += -y / x
                y += cnt * x
            while max(x, y) < m:
                if x > y:
                    y += x
                else:
                    x += y
                cnt += 1
            print cnt

if __name__ == '__main__':
    main()