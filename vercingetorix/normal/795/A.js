var a = readline().split(' ');
var c1=+a[1];
var c2=+a[2];
var n=+a[0];
s=readline();

var m=+n;
var p=+0;
for (var i = 0; i < n; i++) {
    if(s.charAt(i)=="1") p=p+1;
}
var ans=c1+c2*(n-1)*(n-1);
for (var i=1; i<=p; i++) {
    var q = Math.floor(n/i);
    var r = n % i;
    ans = Math.min(ans, r*(c1+c2*q*q) + (i-r)*(c1+c2*(q-1)*(q-1)));
}
print(ans);