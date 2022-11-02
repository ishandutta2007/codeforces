{$r-,q-,s-,i-,o+}
{$M 10000000}
const
  base=29;

var
  ii,rr,ans,kg,j,x,y,m,pv,n,i:longint;
  pw,hash:array[0..400500]of qword;
  uc:array[0..400500,0..18]of qword;
  ux:array[0..400500,0..18]of longint;
  s:ansistring;
  _:char;
  prx,pred,last,g:array[0..700700]of longint;
  chx:array[0..700700]of char;
  
  procedure add(x,y:longint);
    begin
      inc(kg);g[kg]:=y;pred[kg]:=last[x];last[x]:=kg;
    end;
    
  procedure dfs(x:longint);
    var
      i,ii:longint;
    begin
      ux[x][0]:=prx[x];
      uc[x][0]:=ord(chx[x])-96;
      for i:=1 to 18 do begin
        ux[x][i]:=ux[ux[x][i-1]][i-1];
        uc[x][i]:=uc[ux[x][i-1]][i-1]*pw[1 shl (i-1)]+uc[x][i-1];
      end;
      ii:=last[x];
      while (ii>0)do begin
        dfs(g[ii]);
        ii:=pred[ii];
      end;
    end;

begin
  //assign(input,'input.txt');reset(input);
  readln(n);
  m:=n;
  for i:=2 to n do begin
    readln(pv,_,s);
    x:=i;
    for j:=length(s)downto 1 do begin
      if (j=1)then y:=pv else begin
        inc(m);y:=m;
      end;
      prx[x]:=y;
      chx[x]:=s[j];
      x:=y;
    end;
  end;
  readln(s);
  n:=m;
  pw[0]:=1;
  for i:=1 to n do pw[i]:=pw[i-1]*base;
  hash[0]:=0;
  for i:=1 to length(s) do hash[i]:=hash[i-1]+pw[n-i]*(ord(s[i])-96);
  for i:=2 to n do add(prx[i],i);
  dfs(1);
  ans:=0;
  for i:=2 to n do begin
    rr:=length(s);
    x:=i;
    for j:=18 downto 0 do 
      if (1 shl j<=rr)then begin
        if (ux[x][j]=0)or(uc[x][j]*pw[n-rr]<>hash[rr]-hash[rr-(1 shl j)])then begin
          rr:=-1;break;
        end;
        dec(rr,1 shl j);
        x:=ux[x][j];
      end;
    inc(ans,ord(rr=0));
  end;
  writeln(ans);
end.