var l = readline().split(' ');
var b = readline();

for (var i = 0; i < 3; i++)
  l[i] = parseInt(l[i]);

var k = 0;
var n = l[0];
for (var i = 0; i < b.length; i++) {
  if (b[i] == '1')
    k++;
}

var res = l[1] + l[2]*(n-1)*(n-1);

for (var i = 1; i <= k; i++) {
  var loc = l[1]*i;

  var fl = Math.floor(n/i) - 1;
  var cl = Math.ceil(n/i) - 1;

  fl = fl*fl;
  cl = cl*cl;

  loc += cl*(n%i)*l[2];
  loc += fl*(i - (n%i))*l[2];

  if (loc < res)
    res = loc;
}


print(res);