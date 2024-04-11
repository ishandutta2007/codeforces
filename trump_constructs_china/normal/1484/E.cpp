
// Copyright (C) 2021 JacderZhang
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.


#ifndef SCANNER_H_
#define SCANNER_H_ 1
#include <stdio.h>
#include <stdlib.h>
class Scanner {
private:
  static const int BUFFER_SIZE = 1 << 18;
  char buff[BUFFER_SIZE];
  char *buffPos, *buffLim;
  FILE *file;

public:
  Scanner(FILE *file) {
    this->file = file;
    buffLim = buff + fread(buff, 1, BUFFER_SIZE, file);
    buffPos = buff; }

private:
  inline void flushBuff() {
    buffLim = buff + fread(buff, 1, BUFFER_SIZE, file);
    if (buffLim == buff) {
      *buffLim++ = '\n'; }
    buffPos = buff; }
  inline bool isWS(char t) {
    return t <= ' '; }
  inline bool isDig(char t) {
    return t >= '0' && t <= '9'; }
  inline void nextPos() {
    buffPos++;
    if (buffPos == buffLim) {
      flushBuff(); } }
public:
  inline char getchar() {
    char ch = *buffPos;
    nextPos();
    return ch; }
  inline void next(char* s) {
    while (isWS(*buffPos)) {
      nextPos(); }
    while (!isWS(*buffPos)) {
      *s = *buffPos;
      s++;
      nextPos(); }
    *s = '\0'; }
  inline void nextLine(char* s) {
    while (*buffPos != '\n') {
      nextPos(); }
    if (*buffPos == '\n') {
      nextPos(); }
    while (*buffPos != '\n') {
      *s++ = *buffPos;
      nextPos(); }
    *s = '\0'; }
  inline int nextInt() {
    while (!isDig(*buffPos) && *buffPos != '-') {
      nextPos(); }
    int sign = (*buffPos == '-') ? nextPos(), -1 : 1;
    int res = 0;
    while (isDig(*buffPos)) {
      res = res * 10 + *buffPos - '0';
      nextPos(); }
    return res * sign; }
  inline long long nextLong() {
    while (!isDig(*buffPos) && *buffPos != '-') {
      nextPos(); }
    long long sign = (*buffPos == '-') ? nextPos(), -1 : 1;
    long long res = 0;
    while (isDig(*buffPos)) {
      res = res * 10 + *buffPos - '0';
      nextPos(); }
    return res * sign; }
  inline int n() {
    while (*buffPos < '0' || *buffPos > '9') {
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff(); } }
    int res = 0;
    while (*buffPos >= '0' && *buffPos <= '9') {
      res = res * 10 + (*buffPos - '0');
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff(); } }
    return res; }
  inline long long nl() {
    while (*buffPos < '0' || *buffPos > '9') {
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff(); } }
    long long res = 0;
    while (*buffPos >= '0' && *buffPos <= '9') {
      res = res * 10 + (*buffPos - '0');
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff(); } }
    return res; }
  inline long long nlm(const int MOD) {
    while (*buffPos < '0' || *buffPos > '9') {
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff(); } }
    long long res = 0;
    while (*buffPos >= '0' && *buffPos <= '9') {
      res = (res * 10 + (*buffPos - '0')) % MOD;
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff(); } }
    return res; }
  inline double nextDouble() {
    while (isWS(*buffPos)) {
      nextPos(); }
    int sign = (*buffPos == '-') ? nextPos(), -1 : 1;
    double res = 0;
    while (isDig(*buffPos)) {
      res = res * 10 + *buffPos - '0';
      nextPos(); }
    if (*buffPos == '.') {
      nextPos();
      double ep = 1;
      while (isDig(*buffPos)) {
        ep *= 0.1;
        res += ep * (*buffPos - '0');
        nextPos(); } }
    return sign * res; }
  inline char nextChar() {
    while (isWS(*buffPos))
      nextPos();
    char res = *buffPos;
    nextPos();
    return res; }
  ~Scanner() {
    fclose(file); } };
#ifndef SCANNER_H_CUSTOM
Scanner sc(stdin);
#endif
#endif /* SCANNER_H_ */
#ifndef LOG_H_
#define LOG_H_ 1

#include <iostream>
#include <utility>
#include <iterator>
#include <string>

template<class __TyFirst, class __TySecond>
std::ostream&
operator<<(std::ostream& out, const std::pair<__TyFirst, __TySecond>& o)
{
  out << "(" << o.first << "," << o.second << ")";
  return out;
}

std::string cout_list_sep = " ";

template<class IterateType, typename = decltype(std::declval<IterateType>().begin()),
                            typename = decltype(std::declval<IterateType>().end()),
                            typename = typename std::enable_if<std::is_convertible<
                                typename std::iterator_traits< typename IterateType::iterator> ::iterator_category,
                                std::input_iterator_tag> ::value> ::type,
                            typename = typename std::enable_if<!std::is_same<std::string, typename std::decay<IterateType>::type>::value>::type,
                            typename value_type = typename IterateType::value_type>
std::ostream& operator<< (std::ostream& out, const IterateType& a)
{
  for (const auto& i: a) 
    out << i << cout_list_sep;
  return out; 
}

#ifdef __LOCALE__

template<typename T>
void
__ses(const T& a)
{
  std::cout << a << " ";
}
template<typename T, typename... Args>
void
__ses(const T& a, Args... b)
{
  std::cout << a << " ";
  __ses(b...);
}
#define ses(...)                                                               \
  {                                                                            \
    std::cout << #__VA_ARGS__ << " = ";                                        \
    __ses(__VA_ARGS__);                                                        \
  }
#define see(...)                                                               \
  {                                                                            \
    ses(__VA_ARGS__);                                                          \
    std::cout << std::endl;                                                    \
  }
#define slog(format, ...) printf(format "\n", __VA_ARGS__)

static constexpr char __log_space[] = " ";
template<typename _ForwardIterator>
void
logArray(_ForwardIterator __begin,
         _ForwardIterator __end,
         const char* __sep = 0)
{
  if (__sep == 0) {
    __sep = __log_space;
  }
  while (__begin != __end) {
    std::cout << *__begin << *__sep;
    ++__begin;
  }
  std::cout << std::endl;
}

#else

#define see(...)
#define ses(...)
#define slog(format, ...)
template<typename _ForwardIterator>
void
logArray(_ForwardIterator __begin,
         _ForwardIterator __end,
         const char* __sep = 0)
{}

#endif

#endif /* LOG_H_ */
#ifndef RANGE_H_
#define RANGE_H_

#include <stdexcept>
#include <iterator>
#include <type_traits>

template <typename _IntType>
class range {
  static_assert(std::is_integral<_IntType>::value, "range object must have integral value type");

public:
  class iterator : public std::iterator<std::input_iterator_tag, _IntType, _IntType, const _IntType*, _IntType> {
    _IntType val, step;

  public:
    using typename std::iterator<std::input_iterator_tag, _IntType, _IntType, const _IntType*, _IntType>::reference;
    explicit constexpr iterator(int val, int step) noexcept : val(val), step(step) {}
    constexpr iterator& operator++() noexcept { val += step; return *this; }
    constexpr iterator& operator++(int) noexcept { iterator ret = *this; val += step; return ret; }
    constexpr bool operator== (const iterator& rhs) const noexcept { return val == rhs.val; }
    constexpr bool operator!= (const iterator& rhs) const noexcept { return val != rhs.val; }
    constexpr reference operator*() const { return val; }
  };

  typedef  _IntType value_type;
  const value_type _begin, _step, _end;

  explicit constexpr range(const value_type end) noexcept : _begin(0), _step(1), _end(end>0 ? end : 0) {}
  explicit constexpr range(const value_type begin, const value_type end) noexcept : 
    _begin(begin), _step(1), _end(end>begin ? end : begin) {}
  explicit constexpr range(const value_type begin, const value_type end, const value_type step) :
    _begin(begin), _step(step), _end(
      ((step>0&&end<=begin) || (step<0&&end>=begin)) ? begin :
      (step>0 ? begin+(end-begin+step-1)/step*step : begin+(begin-end-step-1)/(-step)*step)) {}
  constexpr iterator begin() const noexcept { return iterator(_begin, _step); }
  constexpr iterator end() const noexcept { return iterator(_end, _step); }
};

#endif
#ifndef UTIL_H_
#define UTIL_H_ 1

#ifndef VECTOR_H_
#define VECTOR_H_

#include <cstdlib>
#include <utility>
#include <iterator>
#include <initializer_list>
#include <type_traits>

namespace Temps {

template <class Type>
class Vector {

public:
  typedef Type         value_type;
  typedef unsigned int size_type;
  typedef Type&        reference;
  typedef const Type&  const_reference;

  class iterator : public std::iterator<std::random_access_iterator_tag, value_type> {
  public:
    friend class Vector;
    using typename std::iterator<std::random_access_iterator_tag, value_type>::difference_type;
    using typename std::iterator<std::random_access_iterator_tag, value_type>::pointer;
    using typename std::iterator<std::random_access_iterator_tag, value_type>::reference;
  
  private:
    pointer ptr;
    iterator(pointer ptr) : ptr(ptr) {}

  public:
    bool operator== (const iterator rhs) const { return ptr == rhs.ptr; }
    bool operator!= (const iterator rhs) const { return ptr != rhs.ptr; }
    bool operator<  (const iterator rhs) const { return ptr <  rhs.ptr; }
    bool operator<= (const iterator rhs) const { return ptr <= rhs.ptr; }
    bool operator>  (const iterator rhs) const { return ptr >  rhs.ptr; }
    bool operator>= (const iterator rhs) const { return ptr >= rhs.ptr; }

    iterator operator++ ()    { return iterator(++ptr); }
    iterator operator++ (int) { return iterator(ptr++); }
    iterator operator-- ()    { return iterator(--ptr); }
    iterator operator-- (int) { return iterator(ptr--); }

    iterator operator+ (const difference_type dif) const { return iterator(ptr + dif); }
    iterator operator- (const difference_type dif) const { return iterator(ptr - dif); }
    iterator operator+= (const difference_type dif) { ptr += dif; return *this; }
    iterator operator-= (const difference_type dif) { ptr -= dif; return *this; }

    difference_type operator- (const iterator& rhs) const { return ptr - rhs.ptr; }

    operator pointer() { return ptr; }
  };


protected:
  value_type *a = nullptr;
  size_type _capacity=0, _size=0;

  void __grow_capacity(size_type least_size) {
    if (_capacity >= least_size) { return; }
    if (_capacity == 0) { _capacity = 1; }
    while (_capacity < least_size) { _capacity = _capacity * 2; }
    a = static_cast<value_type*>(realloc(a, sizeof(value_type) * _capacity)); }

public:
  Vector() =default;
  explicit Vector(size_type size, const value_type& initial_value = value_type()) : _capacity(size), _size(size) {
    a = static_cast<value_type*>(malloc(sizeof(value_type) * _capacity));
    value_type *__first = a, *const __last = a + _size;
    while (__first != __last) { *__first++ = initial_value; } }

  explicit Vector(const Vector& rhs) : _capacity(rhs._size), _size(rhs._size) {
    a = static_cast<value_type*>(malloc(sizeof(value_type) * _capacity));
    value_type *__first = a, *__r_p = rhs.a, *const __last = a + _size;
    while (__first != __last) { *__first++ = *__r_p++; } }
  explicit Vector(Vector&& rhs) : _capacity(rhs._capacity), _size(rhs._size) {
    a = rhs.a; rhs.a = nullptr; }
  
  explicit Vector(const std::initializer_list<value_type>& list) : _capacity(list.size()), _size(list.size()) {
    a = static_cast<value_type*>(malloc(sizeof(value_type) * _capacity));
    value_type *p = a; for (const auto& i: list) { *p++ = i; } }

  template <typename _InputIterator, typename = typename 
            std::enable_if<std::is_convertible<typename std::iterator_traits<_InputIterator>::iterator_category,
                                               std::input_iterator_tag>::value>::type>
  explicit Vector(_InputIterator __first, _InputIterator __last) {
    _size = _capacity = std::distance(__first, __last);
    a = static_cast<value_type*>(malloc(sizeof(value_type) * _capacity));
    value_type *p = a; while (__first != __last) { *p++ = *__first++; } }

  inline bool empty() const { return _size == 0; }
  inline size_type size() const { return _size; }
  inline size_type capacity() const { return _capacity; }

  void reserve(size_type __capacity) {
    _capacity = __capacity;
    if (_size > _capacity) { _size = _capacity; }
    a = static_cast<value_type*>(realloc(a, sizeof(value_type) * _capacity)); }
  void resize(size_type  __size) {
    if (_size > __size) { _size = __size; return; }
    __grow_capacity(__size);
    value_type *__un = a + _size, *const __ed = a + __size;
    while (__un != __ed) { *__un++ = value_type(); }
    _size = __size; }

  Vector& operator= (const Vector& rhs) {
    __grow_capacity(rhs._size);
    _size = rhs._size;
    value_type *__first = a;
    const value_type *const __last = a+_size, *__r_p = rhs.a;
    while (__first != __last) { *__first++ = *__r_p++; }
    return *this; }
  Vector& operator= (Vector&& rhs) {
    _size = rhs._size; _capacity = rhs._capacity;
    a = rhs.a; rhs.a = nullptr; 
    return *this; }

  value_type operator[] (const size_type id) const { return a[id]; }
  value_type& operator[] (const size_type id) { return a[id]; }
  value_type front() const { return a[0]; }
  value_type& front() { return a[0]; }
  value_type back() const { return a[_size - 1]; }
  value_type& back() { return a[_size - 1]; }
  void pop_back() { _size--; }

  Vector& push_back(const value_type& b) {
    __grow_capacity(_size + 1); a[_size] = b; _size++; return *this; }
  Vector& push_back(value_type&& b) {
    __grow_capacity(_size + 1); a[_size] = std::forward<value_type>(b); _size++; return *this; }
  Vector& push_back(const Vector& rhs) {
    __grow_capacity(_size + rhs._size);
    for (const auto& i: rhs) { a[_size++] = i; } 
    return *this; }
  Vector& push_back(const std::initializer_list<value_type>& rhs) {
    __grow_capacity(_size + rhs.size());
    for (const auto& i: rhs) { a[_size++] = i; } 
    return *this; }

  inline iterator begin() const { return iterator(a); }
  inline iterator end() const { return iterator(a + _size); }

  ~Vector() { free(a); }

};

} /* namespace Temps */

#endif /* VECTOR_H_ */

#ifdef NOT_HEADER

#include <set>
#include <iostream>
#include <algorithm>
#ifndef LOG_H_
#define LOG_H_ 1

#include <iostream>
#include <utility>
#include <iterator>
#include <string>

template<class __TyFirst, class __TySecond>
std::ostream&
operator<<(std::ostream& out, const std::pair<__TyFirst, __TySecond>& o)
{
  out << "(" << o.first << "," << o.second << ")";
  return out;
}

std::string cout_list_sep = " ";

template<class IterateType, typename = decltype(std::declval<IterateType>().begin()),
                            typename = decltype(std::declval<IterateType>().end()),
                            typename = typename std::enable_if<std::is_convertible<
                                typename std::iterator_traits< typename IterateType::iterator> ::iterator_category,
                                std::input_iterator_tag> ::value> ::type,
                            typename = typename std::enable_if<!std::is_same<std::string, typename std::decay<IterateType>::type>::value>::type,
                            typename value_type = typename IterateType::value_type>
std::ostream& operator<< (std::ostream& out, const IterateType& a)
{
  for (const auto& i: a) 
    out << i << cout_list_sep;
  return out; 
}

#ifdef __LOCALE__

template<typename T>
void
__ses(const T& a)
{
  std::cout << a << " ";
}
template<typename T, typename... Args>
void
__ses(const T& a, Args... b)
{
  std::cout << a << " ";
  __ses(b...);
}
#define ses(...)                                                               \
  {                                                                            \
    std::cout << #__VA_ARGS__ << " = ";                                        \
    __ses(__VA_ARGS__);                                                        \
  }
#define see(...)                                                               \
  {                                                                            \
    ses(__VA_ARGS__);                                                          \
    std::cout << std::endl;                                                    \
  }
#define slog(format, ...) printf(format "\n", __VA_ARGS__)

static constexpr char __log_space[] = " ";
template<typename _ForwardIterator>
void
logArray(_ForwardIterator __begin,
         _ForwardIterator __end,
         const char* __sep = 0)
{
  if (__sep == 0) {
    __sep = __log_space;
  }
  while (__begin != __end) {
    std::cout << *__begin << *__sep;
    ++__begin;
  }
  std::cout << std::endl;
}

#else

#define see(...)
#define ses(...)
#define slog(format, ...)
template<typename _ForwardIterator>
void
logArray(_ForwardIterator __begin,
         _ForwardIterator __end,
         const char* __sep = 0)
{}

#endif

#endif /* LOG_H_ */

using namespace Temps;
int main() {
  Vector<int> a{3,2,1};
  Vector<int> b{6,5};
  a.push_back({4}).push_back(b);
  std::sort(a.begin(), a.end());
  Vector<int> c(a);
  Vector<int> d(a.begin(), a.end());
  std::set<int> x{1,5,3,4,2};
  Vector<int> e(x.begin(), x.end());
  logArray(c.begin(), c.end());
  logArray(d.begin(), d.end());
  logArray(e.begin(), e.end());
  return 0;
}

#endif /* NOT_HEADER */
#include <algorithm>

template<class T>
inline bool
checkMin(T& a, T b)
{ return (b < a ? a = b, 1 : 0); }

template<class T>
inline bool
checkMax(T& a, T b)
{ return (a < b ? a = b, 1 : 0); }

template <class ForwardIterator, class OutputIterator>
void dissociate(ForwardIterator __begin, ForwardIterator __end, OutputIterator __dest) {
  Temps::Vector<typename std::iterator_traits<ForwardIterator>::value_type> values(__begin, __end); 
  std::sort(values.begin(), values.end()); std::unique(values.begin(), values.end()); 
  while (__begin != __end) {
    *__dest = std::distance(values.begin(), std::lower_bound(values.begin(), values.end(), *__begin));
    __dest++; __begin++; } }

#endif /* UTIL_H_ */

#ifndef STREE_H_
#define STREE_H_ 1

#include <algorithm>

namespace STree {

// Template Node for maintain sums
struct NodeSum
{
  int val;
  int tg;
  NodeSum(int val = 0, int tg = 0)
    : val(val)
    , tg(tg)
  {}
  void update(int _val)
  {
    val += _val;
    tg += _val;
  }
  void pushUp(NodeSum a, NodeSum b) { val = a.val + b.val; }
  void pushDown(NodeSum& a, NodeSum& b)
  {
    a.val += tg;
    b.val += tg;
    a.tg += tg;
    b.tg += tg;
    tg = 0;
  }
};

// Template Node for maintain maxs
struct NodeMax
{
  int val;
  int tg;
  NodeMax(int val = 0, int tg = 0)
    : val(val)
    , tg(tg)
  {}
  void update(int _val)
  {
    val += _val;
    tg += _val;
  }
  void pushUp(NodeMax a, NodeMax b) { val = std::max(a.val, b.val); }
  void pushDown(NodeMax& a, NodeMax& b)
  {
    a.val += tg;
    b.val += tg;
    a.tg += tg;
    b.tg += tg;
    tg = 0;
  }
};

// Default STree for maintain maxs
template<int N, class Item = NodeMax>
class STree
{
protected:
  Item a[N * 4];
  int g_l, g_r;

  template<class T>
  void _modify(int l, int r, int sl, int sr, T val, int u)
  {
    if (sl <= l && r <= sr) {
      a[u].update(val);
      return;
    }
    a[u].pushDown(a[u + u], a[u + u + 1]);
    int mid = (l + r) >> 1;
    if (sl <= mid)
      _modify(l, mid, sl, sr, val, u + u);
    if (sr > mid)
      _modify(mid + 1, r, sl, sr, val, u + u + 1);
    a[u].pushUp(a[u + u], a[u + u + 1]);
  }

  Item _query(int l, int r, int sl, int sr, int u)
  {
    if (sl <= l && r <= sr) {
      return a[u];
    }
    a[u].pushDown(a[u + u], a[u + u + 1]);
    int mid = (l + r) >> 1;
    if (sl > mid)
      return _query(mid + 1, r, sl, sr, u + u + 1);
    else if (sr <= mid)
      return _query(l, mid, sl, sr, u + u);
    else {
      Item res;
      res.pushUp(_query(l, mid, sl, sr, u + u),
                 _query(mid + 1, r, sl, sr, u + u + 1));
      return res;
    }
  }

public:
  void setLR(int _l, int _r) { g_l = _l, g_r = _r; }
  template<class T>
  void modify(int l, int r, T val)
  {
    if (r > g_r) {
      r = g_r;
    }
    _modify(g_l, g_r, l, r, val, 1);
  }
  Item query(int l, int r) { return _query(g_l, g_r, l, r, 1); }
};

} /* namespace STree */

#endif /* STREE_H_ */
// #include "/home/jack/code/creats/Tree.h"
// #include "/home/jack/code/creats/Graph.h"
// #include "/home/jack/code/creats/Intm.h"
// #include "/home/jack/code/Math/Poly/main.h"

#include <bits/stdc++.h>

// #define MULTIPLE_TEST_CASES_WITH_T
// #define MULTIPLE_TEST_CASES_WITHOUT_T
#ifndef _BODY_MAIN
#define _BODY_MAIN 1

#ifndef CUSTOM_MAIN
void
preInit();
void
init();
void
solve();
int32_t
main()
{
  preInit();
#ifdef MULTIPLE_TEST_CASES_WITH_T
  int T;
#ifdef SCANNER_H_
  T = sc.nextInt();
#else
  scanf("%d", &T);
#endif /* SCANNER_H_ */
  while (T--) {
    init();
    solve();
  }
#else
#ifdef MULTIPLE_TEST_CASES_WITHOUT_T
  while (1) {
    try {
      init();
    } catch (bool t) {
      return 0;
    }
    solve();
  }
#else
  init();
  solve();
#endif /* MULTIPLE_TEST_CASES_WITHOUT_T  */
#endif /* MULTIPLE_TEST_CASES_WITH_T */
  return 0;
}
#endif /* CUSTOM_MAIN */

#endif /* _BODY_MAIN */
// #define int long long

/** My code begins here **/

constexpr int N = 300005;
int a[N], b[N], pre[N], n;
long long pv[N], dp[N];

struct Node
{
  long long val;
  long long tg;
  Node(long long val = 0, long long tg = 0)
    : val(val)
    , tg(tg)
  {}
  void update(long long _val)
  {
    val += _val;
    tg += _val;
  }
  void pushUp(Node a, Node b) { val = std::max(a.val, b.val); }
  void pushDown(Node& a, Node& b)
  {
    a.val += tg;
    b.val += tg;
    a.tg += tg;
    b.tg += tg;
    tg = 0;
  }
};

STree::STree<N, Node> T;

void preInit() { } void init() {
  n = sc.n();
  for (int i: range(n)) a[i] = sc.n();
  for (int i: range(n)) b[i] = sc.nextInt();
  std::stack<std::pair<int,int>> le;
  le.push({-1,-1});
  for (int i: range(n)) {
    while (le.top().first > a[i]) { le.pop(); }
    pre[i] = le.top().second;
    le.push({a[i], i}); }
} void solve() {
  T.setLR(-2, n+2);
  T.modify(-1,-1,0);
  for (int i: range(n)) {
    pv[i] = T.query(pre[i], i-1).val + b[i];
    if (pre[i] != -1)  { checkMax(pv[i], pv[pre[i]]); }
    dp[i] = pv[i];
    T.modify(i,i,dp[i]); }
  printf("%lld\n",dp[n-1]);
}