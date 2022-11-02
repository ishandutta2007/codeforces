{$r+,q+,s+,i+,o-}
{$M 10000000}
var
  kg,i,n,x,y,ans1,min,cr:longint;
  k0,k1,g,pred,last,p:array[0..500500]of longint;

  procedure dfs(x,px:longint);
    var
      ii:longint;
      
    begin
      ii:=last[x];
      while (ii>0)do begin
        if (g[ii]<>px)then begin
          k0[g[ii]]:=k0[x]+ord(p[ii]=0);
          k1[g[ii]]:=k1[x]+ord(p[ii]=1);
          inc(ans1,ord(p[ii]=1));
          dfs(g[ii],x);
        end;
        ii:=pred[ii];
      end;
    end;

begin
  {assign(input,'input.txt');reset(input);
  assign(output,'output.txt');rewrite(output);}
  read(n);
  kg:=0;
  fillchar(last,sizeof(last),$0);
  for i:=1 to n-1 do begin
    read(x,y);
    inc(kg);g[kg]:=y;p[kg]:=0;pred[kg]:=last[x];last[x]:=kg;
    inc(kg);g[kg]:=x;p[kg]:=1;pred[kg]:=last[y];last[y]:=kg;
  end;
  ans1:=0;
  dfs(1,0);
  min:=ans1;
  for i:=2 to n do begin
    cr:=ans1-k1[i]+k0[i];
    if (cr<min)then min:=cr;
  end;
  writeln(min);
  for i:=1 to n do begin
    cr:=ans1-k1[i]+k0[i];
    if (cr=min)then write(i,' ');
  end;
end.