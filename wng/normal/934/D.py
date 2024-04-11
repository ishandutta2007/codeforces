p,k=[int(kk) for kk in raw_input().split(" ")]


def negaternary(i,nbn):
    if i == 0:
        digits = ['0']
    else:
        digits = []
        while i != 0:
            i, remainder = i/ nbn, i%nbn
            if remainder < 0:
                i, remainder = i + 1, remainder - nbn
            digits.append(str(remainder))
    return digits[::-1]

a=negaternary(p,-k)

print len(a)
print " ".join(a[::-1])