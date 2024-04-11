s = input().replace(';', ',').split(',')
a = []
b = []
for w in s:
    if w.isdigit() and (w == '0' or w[0] != '0'):
        a.append(w)
    else:
        b.append(w)
for v in a, b:
    print('"{}"'.format(','.join(v)) if v else '-')