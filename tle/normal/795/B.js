var r=readline().split(' ');
var n=+r[0];
var m=+r[1];
var d=+r[2];
var p1=[],p2=[];
var q1=[],q2=[],s1=0,s2=0;
var r1=[],r2=[],g1=0,g2=0;
for(var i=0;i<n;i++)
{
    var s=readline().split(' ');
    p1.push([+s[0],+s[1]]);
}
for(var i=0;i<m;i++)
{
    var s=readline().split(' ');
    p2.push([+s[0],+s[1]]);
}
function cmp(a,b)
{
    if(a[0]!=b[0]) return b[0]-a[0];
    return a[1]-b[1];
}
p1.sort(cmp)
for(var i=0;i<n;i++)
{
    s1=s1+p1[i][0];
    g1=g1+p1[i][1];
    q1.push(s1);
    r1.push(g1);
}
p2.sort(cmp)
for(var i=0;i<m;i++)
{
    s2=s2+p2[i][0];
    g2=g2+p2[i][1];
    q2.push(s2);
    r2.push(g2);
}
var pt=m-1,ans=0;
for(var i=0;i<n;i++)
{
    while(pt>=0&&r2[pt]+r1[i]>d) --pt;
    if(pt<0) continue;
    var cur=q1[i]+q2[pt];
    if(cur>ans) ans=cur;
}
print(ans);