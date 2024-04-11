{$r-,q-,s-,i-,o+}
var
  sum,s1,s2:int64;
  ans:extended;
  a,b:ansistring;
  kt,n,i:longint;
  ch:char;
  t1,t2:array[0..500500]of longint;
  p,g:array['A'..'Z',0..500500]of longint;
  kg:array['A'..'Z']of longint;
  
  procedure qs(l,r:longint);
    var
      i,j,tmp,xx:longint;
      
    begin
      i:=l;j:=r;
      xx:=t1[l+random(r-l+1)];
      while (i<=j)do begin
        while (xx>t1[i])do inc(i);
        while (xx<t1[j])do dec(j);
        if (i>j)then break;
        tmp:=t1[i];t1[i]:=t1[j];t1[j]:=tmp;
        tmp:=t2[i];t2[i]:=t2[j];t2[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qs(i,r);
      if (j>l)then qs(l,j);
    end;

begin
//  assign(input,'input.txt');reset(input);
  randomize;
  readln(n);
  readln(a);
  readln(b);
  for i:=1 to n do begin
    inc(kg[a[i]]);
    g[a[i]][kg[a[i]]]:=i;
    p[a[i]][kg[a[i]]]:=1;
  end;  
  for i:=1 to n do begin
    inc(kg[b[i]]);
    g[b[i]][kg[b[i]]]:=i;
    p[b[i]][kg[b[i]]]:=2;
  end;
  sum:=0;
  for i:=1 to n do sum:=sum+int64(i)*i;
  ans:=0;
  for ch:='A' to 'Z' do begin
    kt:=0;
    for i:=1 to kg[ch] do begin
      inc(kt);
      t1[kt]:=g[ch][i];
      t2[kt]:=p[ch][i];
    end;
    qs(1,kt);
    s1:=0;s2:=0;
    for i:=1 to kt do begin
      if (i<kt)and(t1[i]=t1[i+1])then begin
        if (t2[i+1]=1)then s1:=s1+t1[i+1] else s2:=s2+t1[i+1];
      end;
      if (t2[i]=1)
        then ans:=ans+s2*(n-t1[i]+1)/sum
        else ans:=ans+s1*(n-t1[i]+1)/sum;
      if (i>1)and(t1[i]=t1[i-1])then begin
        ans:=ans-int64(t1[i])*(n-t1[i]+1)/sum;
        continue;
      end;
      if (t2[i]=1)then s1:=s1+t1[i];
      if (t2[i]=2)then s2:=s2+t1[i];
    end;
  end;
  writeln(ans:0:10);
end.