var n = +readline();
var arr = readline().split(" ");

for (var i = 0; i < n; i++)
    arr[i] = +arr[i];

if (n % 7 === 0)
{
    var minidx = 0;
    for (var i = 1; i < n; i++)
    {
        if (i % 7 === 6) continue;
        if (arr[minidx] > arr[i]) minidx = i;
    }
    print(minidx + 1);
}
else
{
    var sub = 1e100;
    for (var i = 0; i < n; i++)
    {
        var f = ((arr[i] - 1) / 6 | 0) * 6;
        if (sub > f) sub = f;
    }

    for (var i = 0; i < n; i++)
        arr[i] -= sub;
        
    for (var i = 0; i < 14 * n; i++)
    {
        if (i % 7 === 6) continue;
        if (--arr[i % n] === 0)
        {
            print(i % n + 1);
            break;
        }
    }
}