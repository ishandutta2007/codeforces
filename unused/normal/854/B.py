n, k = map(int, raw_input().split())

if k == 0 or k == n:
    print '0 0'
    exit()
    
print '1 %d' % min(n - k, k * 2)